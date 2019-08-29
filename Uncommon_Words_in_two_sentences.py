class Solution:
    def uncommonFromSentences(self, A: str, B: str) -> List[str]:
        A=A.split()
        B=B.split()
        words_A={}
        for i in A:
            if i in words_A:
                words_A[i]+=1
            else:
                words_A[i]=1
        ret=[]
        words_B={}
        for word in B:
            if word in words_B:
                words_B[word]+=1
            else:
                words_B[word]=1
        for word in B:
            if word not in words_A and words_B[word]==1:
                ret.append(word)
        for word in A:
            if word not in words_B and words_A[word]==1:
                ret.append(word)
        return ret