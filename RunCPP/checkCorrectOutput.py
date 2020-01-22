# Open Correct Output File.
fileCorrectOuput = open('./RunCPP/correctOutput.txt')
array = []
for line in fileCorrectOuput:
    array.append(line)

fileOutput = open('./RunCPP/output.txt')
iterator = 0
# Loop to check if all output match.
for line in fileOutput:
    if (line == array[iterator] and len(line) > 0 and len(array[iterator]) > 0):
        print("PASSED, Output:: ",line," Correct Output:: ",array[iterator])
    elif(len(line) > 0 and len(array[iterator]) > 0):
        print("FAILED, Output:: ", line, " Correct Output:: ", array[iterator])
    iterator+=1

# Close File.
fileCorrectOuput.close()
fileOutput.close()
