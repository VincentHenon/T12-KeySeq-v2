// Ghidra post-script: export all functions discovered by Auto Analysis.
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;

public class ExportDecompiled extends GhidraScript {
    @Override
    public void run() throws Exception {
        // This PWM interrupt handler is installed through a function pointer,
        // so automatic discovery does not always mark it as a function.
        if (getFunctionAt(toAddr(0x10003228L)) == null) {
            createFunction(toAddr(0x10003228L), "pwm_irq");
        }
        File output = new File("/private/tmp/t12_doboz_v20_decompiled.c");
        DecompInterface decompiler = new DecompInterface();
        decompiler.setOptions(new DecompileOptions());
        decompiler.toggleCCode(true);
        decompiler.toggleSyntaxTree(false);
        if (!decompiler.openProgram(currentProgram)) {
            throw new RuntimeException("Decompiler could not open program");
        }

        int count = 0;
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(output))) {
            writer.write("/* Reconstructed pseudo-C from Doboz T12 v20 UF2.\n");
            writer.write(" * Names/types are inferred; this is not the original source.\n */\n");
            FunctionIterator functions = currentProgram.getFunctionManager().getFunctions(true);
            while (functions.hasNext()) {
                if (monitor.isCancelled()) break;
                Function function = functions.next();
                DecompileResults result = decompiler.decompileFunction(function, 90, monitor);
                writer.write("\n/* " + function.getName() + " at " + function.getEntryPoint() + " */\n");
                if (result != null && result.decompileCompleted() && result.getDecompiledFunction() != null) {
                    writer.write(result.getDecompiledFunction().getC());
                } else {
                    writer.write("/* Decompilation failed: " + (result == null ? "no result" : result.getErrorMessage()) + " */\n");
                }
                writer.write("\n");
                count++;
            }
        } finally {
            decompiler.dispose();
        }
        println("Exported " + count + " functions to " + output.getAbsolutePath());
    }
}
