INSERT INTO `problemsMetadata` (`problemId`, `problemTitle`, `problemDescription`, `problemInputDescription`, `problemOutputDescription`, `problemConstraints`, `problemSubtask`, `authorId`)
VALUES
    ('range-min-query',
    'Range Minimum Query (RMQ)',
    'You are given an array of integers and a set of queries. Each query specifies a range [L, R], and you need to find the minimum element in that range of the array.',
    'The input consists of two lines. The first line contains the size of the array (n) and the number of queries (q). The second line contains the elements of the array (a1, a2, ..., an) separated by spaces. Each of the following q lines specifies a query with two integers L and R.',
    'For each query, output a single integer representing the minimum element in the specified range of the array.',
    '1 <= n <= 10^5, 1 <= q <= 10^5, -10^9 <= ai <= 10^9, 1 <= L <= R <= n',
    'Subtask 1: 1 <= n, q <= 100, -1000 <= ai <= 1000',
    'AUTHOR006');
