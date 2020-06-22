# Open Correct Output File.
fileCorrectOuput = open('./RunCPP/correctOutput.txt')
array = []
failedInputs = []
for line in fileCorrectOuput:
    array.append(line)

fileOutput = open('./RunCPP/output.txt')
iterator = 0
testCasesPassed = 0
testCasesFailed = 0
# Loop to check if all output match.
for line in fileOutput:
    if(iterator < testCasesFailed + testCasesPassed):
        print("Debugging Right?")
        break
    if (line == array[iterator] and len(line) > 0 and len(array[iterator]) > 0):
        print("PASSED, Output: ",line," Correct Output: ",array[iterator])
        testCasesPassed +=1
    elif(len(line) > 0 and len(array[iterator]) > 0):
        print("FAILED, Output: ", line, " Correct Output: ", array[iterator])
        testCasesFailed +=1
        failedInputs.append([iterator + 1, line, array[iterator]])
    iterator+=1

# Print Total test cases passed.
totalTestCases = testCasesPassed + testCasesFailed
print('#' * 80)
print("Test Cases Passed : ", testCasesPassed," ,Test Cases Failed: ", testCasesFailed," ,Out of total ",totalTestCases)
print('#' * 80)
# Print indices of failed Test cases.
if (testCasesFailed > 0) :
    print()
    print("The code failed for the following test case number(s):")
    for incorrectOutput in failedInputs:
        print('-' * 40)
        print("Failed Test Case : ", incorrectOutput[0])
        print("Your Output : ", incorrectOutput[1], end = "")
        print("Correct Output : ", incorrectOutput[2])
        print('-' * 40)
# Close File.
fileCorrectOuput.close()
fileOutput.close()
