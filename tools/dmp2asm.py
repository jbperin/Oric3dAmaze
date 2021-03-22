import codegen as codegen

FilePathName = "tools/stdchar.dmp"
def main ():
    databuff = []
    with open(FilePathName, 'rb') as fic:
        fileContent = fic.read()
        for byt in fileContent:
            databuff.append(byt)
        print (len(fileContent))
        print (fileContent[0:10])
    print (databuff)
    print (codegen.buffer2cCode("charset", "unsigned char", databuff))
if __name__ == '__main__':
    main()
