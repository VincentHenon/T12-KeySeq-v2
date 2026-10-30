#!/usr/bin/env python3
"""Generate the T12 KeySeq UI navigation diagram as a standalone SVG."""

from html import escape
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
OUT = ROOT / "docs" / "T12_UI_Navigation_v0.1.64.svg"

W, H = 2800, 2100
BG = "#0B0F17"
PANEL = "#121A27"
PANEL_2 = "#182235"
TEXT = "#F2F5FA"
MUTED = "#A7B1C2"
BORDER = "#31415B"
ENC = "#F4A340"
PRESS = "#59A7FF"
HOLD = "#8C7CFF"
BUTTONS = "#65D596"
PADS = "#E875C3"
FLOW = "#8FA2BE"
IDLE = "#FFC857"


def text(x, y, value, size=28, color=TEXT, weight=400, anchor="start", family="Arial, Helvetica, sans-serif"):
    return (
        f'<text x="{x}" y="{y}" fill="{color}" font-family="{family}" '
        f'font-size="{size}" font-weight="{weight}" text-anchor="{anchor}">{escape(value)}</text>'
    )


def multiline(x, y, lines, size=23, color=MUTED, line_h=32, weight=400):
    items = [
        f'<text x="{x}" y="{y}" fill="{color}" font-family="Arial, Helvetica, sans-serif" '
        f'font-size="{size}" font-weight="{weight}">'
    ]
    for i, line in enumerate(lines):
        dy = 0 if i == 0 else line_h
        items.append(f'<tspan x="{x}" dy="{dy}">{escape(line)}</tspan>')
    items.append("</text>")
    return "".join(items)


def pill(x, y, label, color, width=None):
    width = width or max(78, 25 + len(label) * 14)
    return (
        f'<rect x="{x}" y="{y}" width="{width}" height="38" rx="19" fill="{color}" opacity="0.18"/>'
        f'<rect x="{x}" y="{y}" width="{width}" height="38" rx="19" fill="none" stroke="{color}" stroke-width="2"/>'
        + text(x + width / 2, y + 27, label, 19, color, 700, "middle")
    )


def node(x, y, w, h, title, subtitle, lines, accent=PRESS, state=None):
    out = [
        f'<g filter="url(#shadow)">',
        f'<rect x="{x}" y="{y}" width="{w}" height="{h}" rx="24" fill="{PANEL}" stroke="{BORDER}" stroke-width="2"/>',
        f'<rect x="{x}" y="{y}" width="9" height="{h}" rx="4.5" fill="{accent}"/>',
        text(x + 28, y + 43, title, 30, TEXT, 700),
        text(x + 28, y + 73, subtitle, 18, accent, 700),
    ]
    if state:
        out.append(pill(x + w - 107, y + 21, state, IDLE, 82))
    out.append(multiline(x + 28, y + 108, lines, 20, MUTED, 29))
    out.append("</g>")
    return "".join(out)


def edge(path, label="", color=FLOW, label_x=None, label_y=None, dash=False, width=3):
    dash_attr = ' stroke-dasharray="10 9"' if dash else ""
    out = (
        f'<path d="{path}" fill="none" stroke="{color}" stroke-width="{width}" '
        f'stroke-linecap="round" stroke-linejoin="round" marker-end="url(#arrow-{color[1:]})"{dash_attr}/>'
    )
    if label and label_x is not None and label_y is not None:
        box_w = max(100, len(label) * 12 + 24)
        out += f'<rect x="{label_x - box_w/2}" y="{label_y - 23}" width="{box_w}" height="34" rx="10" fill="{BG}" opacity="0.96"/>'
        out += text(label_x, label_y + 1, label, 17, color, 700, "middle")
    return out


def section(x, y, w, h, title, color):
    return (
        f'<rect x="{x}" y="{y}" width="{w}" height="{h}" rx="32" fill="{PANEL_2}" opacity="0.34" '
        f'stroke="{color}" stroke-width="2" stroke-dasharray="8 10"/>'
        + text(x + 28, y + 44, title, 22, color, 700)
    )


parts = [
    f'<svg xmlns="http://www.w3.org/2000/svg" width="{W}" height="{H}" viewBox="0 0 {W} {H}">',
    "<defs>",
    '<filter id="shadow" x="-20%" y="-20%" width="140%" height="150%"><feDropShadow dx="0" dy="10" stdDeviation="12" flood-color="#000" flood-opacity="0.28"/></filter>',
]
for color in [ENC, PRESS, HOLD, BUTTONS, PADS, FLOW, IDLE]:
    parts.append(
        f'<marker id="arrow-{color[1:]}" markerWidth="12" markerHeight="12" refX="10" refY="6" orient="auto" markerUnits="strokeWidth">'
        f'<path d="M0,0 L12,6 L0,12 z" fill="{color}"/></marker>'
    )
parts += ["</defs>", f'<rect width="{W}" height="{H}" fill="{BG}"/>']

# Header
parts += [
    text(90, 82, "T12 KEYSEQ — NAVIGATION & COMMANDES", 43, TEXT, 800),
    text(90, 126, "Firmware v0.1.64 · diagramme basé sur l’implémentation actuelle", 23, MUTED, 400),
    pill(1830, 62, "TOURNER ENCODEUR", ENC, 235),
    pill(2080, 62, "CLIC", PRESS, 110),
    pill(2205, 62, "CLIC LONG", HOLD, 165),
    pill(2385, 62, "− / +", BUTTONS, 110),
    pill(2510, 62, "PADS", PADS, 150),
]

# Section backgrounds
parts += [
    section(70, 175, 760, 1270, "CRÉATION / ÉDITION", PADS),
    section(865, 175, 785, 1270, "NAVIGATION PRINCIPALE", PRESS),
    section(1685, 175, 1045, 1270, "CONFIGURATION", ENC),
]

# Nodes: left
parts.append(node(110, 235, 680, 175, "EDIT KEYS", "KEY ASSIGNMENT", [
    "PAD : choisir la key · ENC : faire défiler les notes",
    "− / + : octave · CLIC LONG : quitter vers Performance",
], PADS, "IDLE"))
parts.append(node(110, 455, 680, 175, "RECORD", "LIVE STEP CAPTURE", [
    "PAD : ajouter une key · une key remplace le pas courant",
    "ENC : naviguer et déclencher le gate · + : fixer le dernier pas",
    "− : effacer la séquence · arrêt à 32 pas · clic long : Menu",
], PADS))
parts.append(node(110, 865, 680, 175, "EDIT STEPS", "STEP BROWSER", [
    "ENC : choisir le pas · PAD : assigner une key · CLIC : paramètres",
    "− : activer/désactiver Rest · + : écouter le pas",
], ENC, "IDLE"))
parts.append(node(110, 1085, 680, 305, "STEP PARAMETERS", "SELECTED STEP", [
    "Gate : single / multi / hold / rest / skip",
    "Length : ×1…×8 · Ratchet : off / 2 / 3 / 4 / 6 / 8",
    "Slide · Vibrato · Variant + degree / min / max",
    "ENC : naviguer/modifier · CLIC : éditer/toggle · − : retour",
], ENC, "IDLE"))

# Nodes: center
parts.append(node(905, 235, 705, 245, "PERFORMANCE", "PLAYBACK", [
    "CLIC : Play / Stop · CLIC LONG : ouvrir Menu",
    "ENC en lecture : choisir le paramètre live · − / + : modifier",
    "ENC à l’arrêt : choisir le pas · − / + : octave séquence",
    "PAD en lecture : priorité CV / arpège · à l’arrêt : preview",
], PRESS))
parts.append(node(905, 545, 705, 265, "MAIN MENU", "6 ENTRIES", [
    "LIVE · STEPS · KEYS · REC · SAVE-LOAD · SETTINGS",
    "Menu vertical : ENC haut/bas · CLIC : ouvrir",
    "SETTINGS contient Scales · Calibration · Clock · Misc",
    "CLIC LONG depuis la plupart des écrans : ouvrir ce menu",
], PRESS))
parts.append(node(905, 875, 705, 145, "SAVE / LOAD", "SLOT LIST", [
    "ENC : choisir un slot · CLIC : ouvrir · − : retour",
], BUTTONS))
parts.append(node(905, 1065, 705, 175, "SLOT ACTIONS", "CURRENT SLOT", [
    "Save with name · Load · Clear · Quick save · Return",
    "CLIC : exécuter l’action · − : retour",
], BUTTONS))
parts.append(node(905, 1285, 705, 115, "NAME", "SAVE LABEL", [
    "ENC : caractère · CLIC : suivant · − : annuler · + : sauver",
], BUTTONS))

# Nodes: right
parts.append(node(1725, 235, 465, 175, "SCALES", "SCALE & ROOT", [
    "Scale · root · remplir les 12 keys",
    "Edit user scale · retour",
], ENC))
parts.append(node(2225, 235, 465, 175, "USER SCALE", "PIANO EDITOR", [
    "ENC : note · CLIC : activer/désactiver",
    "− : annuler · + : sauver",
], ENC, "IDLE"))
parts.append(node(1725, 465, 965, 175, "CLOCK", "TIMING", [
    "Source auto / internal / external · BPM · division · tap tempo",
    "Moniteur Clock In · moniteur Reset In · retour",
], ENC))
parts.append(node(1725, 695, 965, 205, "SETTINGS", "SYSTEM", [
    "SCALES · CV CALIBRATION · CLOCK",
    "MISC : vibrato rate/depth · glide curve · LED brightness",
    "AUX destination · encoder reverse · gate length · save settings",
], ENC))
parts.append(node(1725, 955, 965, 255, "CV CALIBRATION", "PITCH / AUX — 5 POINTS", [
    "Sortie PITCH/AUX · cibles 0 / 2 / 4 / 6 / 8 V",
    "Coarse + Fine · CLIC : éditer/valider · − / + : cible",
    "Maintenir + et tourner ENC : ×10 · CLIC LONG : retour",
], ENC, "IDLE"))
parts.append(node(1725, 1265, 965, 125, "CALIBRATION RESULT", "VERIFY 0…8 V", [
    "− / + : tension de sortie par octave · CLIC LONG : retour",
], ENC, "IDLE"))

# Edges behind the lower legend but above nodes.
edges = []
# Performance <-> menu
edges.append(edge("M1258 480 L1258 545", "LONG CLICK", HOLD, 1370, 520, width=4))
edges.append(edge("M1160 545 L1160 480", "PERFORMANCE", PRESS, 1042, 520, width=4))
# Menu to left branches
edges.append(edge("M905 600 C835 600 850 322 790 322", "EDIT KEYS", PADS, 840, 355))
edges.append(edge("M905 635 C835 635 850 540 790 540", "REC", PADS, 840, 560))
edges.append(edge("M905 700 C835 700 850 952 790 952", "EDIT STEPS", ENC, 840, 925))
edges.append(edge("M450 1040 L450 1085", "CLICK", PRESS, 520, 1070))
edges.append(edge("M110 1160 C70 1160 70 952 110 952", "− / RETURN", BUTTONS, 58, 1055, dash=True))
# Menu to storage
edges.append(edge("M1258 810 L1258 875", "SAVE / LOAD", BUTTONS, 1370, 850))
edges.append(edge("M1258 1020 L1258 1065", "SELECT SLOT", PRESS, 1365, 1053))
edges.append(edge("M1258 1240 L1258 1285", "SAVE WITH NAME", BUTTONS, 1405, 1274))
# Menu to right branches
edges.append(edge("M1610 600 C1660 600 1650 322 1725 322", "SCALES", ENC, 1668, 355))
edges.append(edge("M2190 322 L2225 322", "EDIT USER", PRESS, 2208, 305))
edges.append(edge("M2460 410 L2460 435 C2460 448 2405 448 2405 465", "− / +", BUTTONS, 2525, 442, dash=True))
edges.append(edge("M1610 655 C1660 655 1650 552 1725 552", "CLOCK", ENC, 1668, 575))
edges.append(edge("M1610 710 C1660 710 1650 797 1725 797", "SETTINGS", ENC, 1668, 775))
edges.append(edge("M2207 900 L2207 955", "CV CALIBRATION", PRESS, 2350, 935))
edges.append(edge("M2207 1210 L2207 1265", "SAVE / RESULT", PRESS, 2348, 1245))
# Back hints
edges.append(edge("M1725 1315 C1665 1315 1665 1082 1725 1082", "LONG CLICK", HOLD, 1660, 1190, dash=True))

# Edges need to appear visibly; append after node definitions intentionally.
parts.extend(edges)

# Bottom controls matrix
parts += [
    f'<rect x="70" y="1490" width="2660" height="540" rx="32" fill="{PANEL_2}" stroke="{BORDER}" stroke-width="2"/>',
    text(105, 1540, "RÉSUMÉ DES COMMANDES", 27, TEXT, 800),
    text(105, 1576, "Les mêmes commandes physiques changent de rôle selon l’écran actif.", 20, MUTED, 400),
]

# Matrix columns and headers
cols = [105, 515, 955, 1395, 1845, 2295]
headers = [
    ("ÉCRAN", TEXT),
    ("ENCODEUR", ENC),
    ("CLIC / CLIC LONG", PRESS),
    ("− / +", BUTTONS),
    ("PADS TACTILES", PADS),
    ("ÉTAT CLOCK", IDLE),
]
widths = [380, 410, 410, 420, 420, 400]
for (label, color), x, w in zip(headers, cols, widths):
    parts.append(f'<rect x="{x}" y="1605" width="{w}" height="44" rx="12" fill="{color}" opacity="0.14"/>')
    parts.append(text(x + 16, 1635, label, 18, color, 800))

rows = [
    ("Performance", "paramètre / pas", "Play/Stop · long : Menu", "modifier / octave", "priorité / arp / preview", "RUN ou STOP"),
    ("Edit Keys", "changer la note", "long : quitter", "octave − / +", "choisir la key", "IDLE"),
    ("Record", "—", "finir", "silence / annuler", "ajouter un pas", "RECORD"),
    ("Edit Steps", "choisir le pas", "ouvrir paramètres", "rest / preview", "assigner la key", "IDLE"),
    ("Listes / Settings", "naviguer / éditer", "choisir / valider", "retour / ouvrir", "—", "IDLE si édition"),
    ("Calibration", "choix / coarse / fine", "éditer · long : retour", "tension cible", "—", "IDLE"),
]
row_y = 1690
for i, row in enumerate(rows):
    y = row_y + i * 52
    if i % 2 == 0:
        parts.append(f'<rect x="95" y="{y-29}" width="2605" height="46" rx="9" fill="#FFFFFF" opacity="0.035"/>')
    colors = [TEXT, ENC, PRESS, BUTTONS, PADS, IDLE]
    for value, x, color in zip(row, cols, colors):
        parts.append(text(x + 12, y, value, 18, color, 600 if x == cols[0] else 400))

parts += [
    f'<rect x="95" y="2010" width="2605" height="1" fill="{BORDER}"/>',
    text(105, 2060, "RÈGLE IDLE", 18, IDLE, 800),
    text(245, 2060, "Edit Keys, Edit Steps, Step Parameters et CV Calibration arrêtent la lecture et ignorent l’horloge externe.", 18, MUTED, 400),
    "</svg>",
]

OUT.parent.mkdir(parents=True, exist_ok=True)
OUT.write_text("\n".join(parts), encoding="utf-8")
print(OUT)
