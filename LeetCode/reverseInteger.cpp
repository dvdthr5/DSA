class Solution(object):
    def reverse(self, x):
        array = []
        output = []
        for z in str(x):
            array.append(z)
        
        for y in range(len(array)):
            y += 1
            f = array[(y * -1)]
            output.append(f)
        
        ans = join(output)
        return int(ans)


        
