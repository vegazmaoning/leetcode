```
def solution():
    result = []
    def execute(nums, tmp_list):
        if not nums:
            result.append(tmp_list)
        for i in range(len(nums)):
            execute(nums[:i]+nums[i+1:], tmp_list+[nums[i]])
    execute([1, 2, 3], [])
    return result

```
