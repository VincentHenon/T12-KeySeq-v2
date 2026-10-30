figma.showUI(__html__, { width: 360, height: 260, title: "Bitmap export" });

function safeName(name, index) {
  const clean = (name || `group-${index + 1}`)
    .trim().replace(/[^a-z0-9._-]+/gi, "-").replace(/^-+|-+$/g, "");
  return clean || `group-${index + 1}`;
}

figma.ui.onmessage = async (message) => {
  if (message.type === "list") {
    const selection = figma.currentPage.selection;
    figma.ui.postMessage({ type: "selection", nodes: selection.map((node, index) => ({
      id: node.id, name: node.name || `group-${index + 1}`, type: node.type,
      exportable: "exportAsync" in node
    })) });
    return;
  }
  if (message.type === "export") {
    const selection = figma.currentPage.selection;
    if (!selection.length) {
      figma.ui.postMessage({ type: "error", text: "Select at least one group." });
      return;
    }
    const nodes = selection.filter((node) => "exportAsync" in node);
    if (!nodes.length) {
      figma.ui.postMessage({ type: "error", text: "The selection has no exportable groups." });
      return;
    }
    figma.ui.postMessage({ type: "start", count: nodes.length });
    const names = message.names || [];
    for (let i = 0; i < nodes.length; i++) {
      const node = nodes[i];
      const bytes = await node.exportAsync({ format: "PNG", constraint: { type: "SCALE", value: 1 } });
      figma.ui.postMessage({
        type: "file",
        name: safeName(names[i] || node.name, i),
        bytes: Array.from(bytes),
        index: i + 1,
        count: nodes.length
      });
    }
    figma.ui.postMessage({ type: "done" });
  }
  if (message.type === "close") figma.closePlugin();
};
