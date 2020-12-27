#First line contains number of test cases
testCases = int(input())
#For every test case
for _ in range(testCases):
    #Following line is the number of candidates (n), followed by n lines, ith line representing votes for ith candidate
    numOfCandidates = int(input())
    votes = []
    for _ in range(numOfCandidates):
        #construct the votes test case for each test case 
        votes.append(int(input()))
    
    #if the highest number of votes occurs more than once, then there has been a tie
    if votes.count(max(votes)) > 1:
        print ("no winner")
    #there is a majority if the highest number of votes for a candidate is greater than half of the total votes
    #else (if the candidate did not receive more than half of the votes), they are a minority winner.
    else:
        print("{} winner {}".format(
            "majority" if max(votes) > sum(votes) * 1/2 
            else "minority", 
            votes.index(max(votes)) + 1))
