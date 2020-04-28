# Problem link : https://leetcode.com/problems/first-unique-character-in-a-string/

class FirstUnique:
    
    frequency = dict()

    def __init__(self, nums: List[int]):
        
        self.frequency.clear()
        
        for item in nums: # Adding all numbers in dictionary
            if item not in self.frequency:
                self.frequency[item]=1
            else:
                self.frequency[item]= self.frequency[item]+1

    def showFirstUnique(self) -> int:
        for key,val in self.frequency.items():
            if(val==1):
                return key
        return -1

    def add(self, value: int) -> None:
        if value not in self.frequency:
                self.frequency[value]=1
        else:
                self.frequency[value]= self.frequency[value]+1


# Your FirstUnique object will be instantiated and called as such:
# obj = FirstUnique(nums)
# param_1 = obj.showFirstUnique()
# obj.add(value)