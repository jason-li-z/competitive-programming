class Solution:
    def stringMatching(self, words: List[str]) -> List[str]:
        result = []
        for i in range(len(words)):
            curr = words[i]
            for j in range(len(words)):
                if words[j] != curr and curr in words[j]:
                    result.append(curr)
                    break
        return result
            