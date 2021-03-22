

import struct

def buffer2asmCode(theName, theBuffer):
    theCode = ""
    first = True
    nline = False
    for ii in range(len(theBuffer)):
        if nline == True:
            theCode += f"\n\t.byt "
            nline = False
        elif first:
            theCode += f"_{theName}\n\t.byt "
            first = False
        else:
            theCode += ", "
        if (theBuffer[ii] < 0):
            intv = struct.unpack('B',struct.pack("b", theBuffer[ii]))[0]
        else:
            intv = theBuffer[ii]
        theCode += f"{intv}"
        if ((ii+1) %16 == 0) and (ii != 0):
            # theCode += "\n\t.byt "
            nline = True

    return theCode



def buffer2cCode(theName, theType, theBuffer):
    theCode = ""
    first = True
    for ii in range(len(theBuffer)):
        if first:
            theCode += f"{theType} {theName}[] = {{\n\t"
            first = False
        else:
            theCode += ", "
        theCode += f"{theBuffer[ii]}"
        if ((ii+1) %16 == 0) and (ii != 0):
            theCode += "\n\t"
    theCode += "};\n"
    return theCode

def buffer2pyCode(theName, theBuffer):
    theCode = ""
    first = True
    for ii in range(len(theBuffer)):
        if first:
            theCode += f"{theName} = [\n\t"
            first = False
        else:
            theCode += ", "
        theCode += f"{theBuffer[ii]}"
        if ((ii+1) %16 == 0) and (ii != 0):
            theCode += "\n\t"
    theCode += "]\n"
    return theCode


def main ():
    pass
    # stWall = buffer2cCode("idxWall", "unsigned char", [0 for ii in range(config.NUMBER_OF_SLICE)])
    # stTexCol = buffer2cCode("tabTexCol", "unsigned char", [ii for ii in range(40)])
    # stMulti40 = buffer2cCode("multi40", "unsigned int", [40*ii for ii in range(200)])
    # stMulti120 = buffer2cCode("multi120", "unsigned int", [120*ii for ii in range(64)])
    # stMulti32 = buffer2cCode("multi32", "unsigned int", [32*ii for ii in range(32)])
    # stMultiCoeff = buffer2cCode("multiCoeff", "unsigned char", [round(COEFF*ii) for ii in range(45)])
    # print (stWall)
    # print (stTexCol)
    # print (stMulti40)
    # print (stMulti120)
    # print (stMulti32)
    # print (stMultiCoeff)

if __name__ == "__main__":
    # execute only if run as a script
    main()    
