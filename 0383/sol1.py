class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:

        def create_dict(my_str):
            my_dict = {}

            for letter in my_str:
                if letter in my_dict.keys():
                    my_dict[letter] += 1
                else:
                    my_dict[letter] = 1
            
            return my_dict

        dict_ran = create_dict(ransomNote)
        dict_mag = create_dict(magazine)

        for letter in dict_ran:
            if letter not in dict_mag:
                return False
            if dict_mag[letter] < dict_ran[letter]:
                return False

        return True

# test cases
# ransomNote = "aa"
# magazine = "ab"
ransomNote = "aa"
magazine = "aab"

# test
sol = Solution()
print(sol.canConstruct(ransomNote, magazine))