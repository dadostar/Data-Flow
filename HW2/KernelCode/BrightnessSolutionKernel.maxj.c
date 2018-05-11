/**
 * Document: MaxCompiler Training (maxcompiler-training.pdf)
 * Chapter: 1
 * Exercise Solution: 1
 * Summary:
 *   Kernel that takes a scalar input and adds it to every pixel
 *   to adjust the brightness of an image.
 */
package brightness;

import com.maxeler.maxcompiler.v2.kernelcompiler.Kernel;
import com.maxeler.maxcompiler.v2.kernelcompiler.KernelParameters;
import com.maxeler.maxcompiler.v2.kernelcompiler.types.base.DFEVar;
import com.maxeler.maxcompiler.v2.kernelcompiler.types.base.DFEType;

class BrightnessSolutionKernel extends Kernel {

    BrightnessSolutionKernel(KernelParameters parameters) {
        super(parameters);
        DFEVar inImage = io.input("inImage", dfeInt(32));
        
        DFEType doubleType=dfeFloat(11,53);
        DFEType singleType=dfeFloat(8,24);
        
        int height = 540;
        int width = 720;

        for (int i=0; i<height; i++){
            for (int j=0; j<width; j++){
                
                //mark the pixels as "2" if the neighbor is black
                DFEVar v = inImage[i * width + j];
                inImage[ (i-1) * width + j] <== (i > 0 & inImage[(i-1) * width + j] === constant.var(singleType,0) & v === constant.var(singleType,1)) ? constant.var(singleType,2) : constant.var(singleType,1);
                inImage[ i * width + j - 1] <== j > 0 & inImage[i * width + j - 1] === constant.var(singleType,0) & v === constant.var(singleType,1) ? constant.var(singleType,2) : constant.var(singleType,1);
                inImage[ (i+1) * width + j] <== (i + 1) < height & inImage[(i + 1) * width + j] === constant.var(singleType,0) & v === constant.var(singleType,1)? constant.var(singleType,2) : constant.var(singleType,1);
                inImage[ i * width + j + 1] <== (j + 1) < width & inImage[i * width + j + 1] === constant.var(singleType,0) & v === constant.var(singleType,1)? constant.var(singleType,2) : constant.var(singleType,1);
            }
        }
        
        // if the value is 2 then I make the pixel black to enlarge the black line thickness
        for (int i=0; i<height; i++){
            for (int j=0; j<width; j++){
                inImage[i * width + j] <== inImage[i * width + j] === constant.var(singleType,2)? constant.var(singleType,1) : constant.var(singleType,0);
                
            }
        }
   
        io.output("outImage", inImage, inImage.getType());
    }
}
