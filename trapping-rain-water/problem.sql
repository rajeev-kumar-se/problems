INSERT INTO `problemsMetadata` (`problemId`, `problemTitle`, `problemDescription`, `problemInputDescription`, `problemOutputDescription`, `problemSampleInput`, `problemSampleOutput`, `problemConstraints`, `problemSubtask`, `authorId`)
VALUES
    ('trapping-rain-water',
    'Trapping Rain Water',
    'Given an elevation map, compute how much rainwater can be trapped after it rains.',
    'The input consists of two lines. The first line contains an integer n, representing the number of heights in the elevation map. The second line contains n non-negative integers representing the heights of the elevation map.',
    'Output a single integer representing the total amount of rainwater that can be trapped.',
    'Example 1:
    12
    0 1 0 2 1 0 1 3 2 1 2 1',
    'Example 1:
    6',
    '1 <= n <= 10^5, 0 <= heights[i] <= 10^5',
    'Subtask 1: 1 <= n <= 100, 0 <= heights[i] <= 1000',
    'AUTHOR008');
