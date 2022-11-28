# Happy-Farm
Description

As a hard-working farmer with a grand farm, Bob always takes care of everything in the farm by himself. Planting the crop one by one is so satisfying that he is happy everyday. Happy as Bob is, he is also forgetful. To keep the crop safe, each piece of crop should come with a fence, yet Bob sometimes forgets to set a fence when planting the crop.

In this rural area, thieves come and go. Those notorious thieves steal the crop without protection of a fence. Feeling tired of keeping an eye on all the crop, Bob decides to build a monitor system to keep track of every activity happening in the farm.

In the monitor system, the farm is a 2-dimensional space. The system receives 4 kinds of instructions: 3 instructions recording the activities, and 1 instruction displaying the state in the farm. The instructions are described as follows:

1. Plant
"PLANT x y with_fence" means Bob plants a piece of crop in the position (x, y). with_fence is either 0 or 1, meaning whether Bob sets a fence along with the crop. For example, “PLANT 40 30 1” means Bob plants a piece crop with a fence at (40, 30). If the same position has been access more than once, the amount of the crop doesn't change, while the state of the fence might change. For each position, a fence can only be added but not removed. For example,
"PLANT x y 1" can overwrite "PLANT x y 0" 
"PLANT x y 0" cannot overwrite "PLANT x y 1" 

2. Thief
"THIEF x y" means a thief visits position (x, y). Besides (x, y), the thief also scans (x+1, y), (x-1, y), (x, y+1), (x, y-1). Among the five positions, the crop will be stolen where the fence has not been set. 

3. Super Thief
"SUPER_THIEF x y" means the more dangerous thief visits position (x, y). Besides (x, y), the thief also scans (x+1, y), (x-1, y), (x, y+1), (x, y-1), (x-1, y-1), (x-1, y+1), (x+1, y+1), (x+1, y-1). Among the nine positions, the crop located in the position without a fence will be stolen.

4. Display
"DISPLAY" prints out all the crop’s location from the left to the right, and then the bottom to the top.
