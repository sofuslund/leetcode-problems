class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        letter_dict = {
            '2': 'abc',
            '3': 'def',
            '4': 'ghi',
            '5': 'jkl',
            '6': 'mno',
            '7': 'pqrs',
            '8': 'tuv',
            '9': 'wxyz',
        }
        if len(digits) == 0:
            return []

        combinations = ['']
        for digit in digits:
            letters = letter_dict[digit]
            print(letters)
            new_combinations = []
            for i in range(len(combinations)):
                new_combinations.extend([combinations[i]] * len(letters))
            combinations = new_combinations
            print(combinations)
            for i in range(len(combinations)):
                combinations[i] += letters[i%len(letters)]
            print(combinations)
        
        return combinations

        
