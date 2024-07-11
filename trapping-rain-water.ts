function trap(height: number[]): number {
    // Find max height in list
    let max = 0;
    for (let i = 0; i < height.length; i++) {
        if(height[i] > max)
            max = height[i];
    }

    let result: number = 0;

    // Traverse an 'imaginative' matrix of the elevation map
    for (let y = 0; y < max; y++) {   
        let count: number = 0;
        let x = 0;
        // Move to first 'pixel/block' in row
        while (height[x] < y+1) x++; 
        // Count empty blocks from there
        for (; x < height.length; x++) {
            if(height[x] < y+1) {
                count++;
            } else { // Ensures the right wall is treated as empty
                result += count;
                count = 0;
            }
        }
    }

    return result;
};

// 40 times faster solution
function trap(height: number[]): number {
    let result: number = 0;
    let max_height: number; // Current max height, sets the threshold for how high the water can go
    let max_height_idx: number
    function run(first: number, last: number, direction: 1|-1) {
        max_height = height[first];
        max_height_idx = first;
        for (let i = first + direction; i*direction <= last*direction; i += direction) {
            if (height[i] >= max_height) {
                // A new max height is encountered: measure the trapped water in the newly made hole
                for (let j = max_height_idx+direction; j*direction < i*direction; j += direction) {
                    result += max_height - height[j];
                }

                // Set new max_height
                max_height = height[i];
                max_height_idx = i;
            }
        }
    }

    run(0, height.length-1, 1); // Approach the heighest pillar from left
    run(height.length-1, max_height_idx, -1); // Approach the heighest pillar from right

    return result;
};
