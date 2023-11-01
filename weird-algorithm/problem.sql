INSERT INTO `problemsMetadata` (`problemId`, `problemTitle`, `problemDescription`, `problemInputDescription`, `problemOutputDescription`, `problemConstraints`, `problemSubtask`, `authorId`)
VALUES
    ('collatz-conjecture',
    'Collatz Conjecture',
    'Consider an algorithm that takes as input a positive integer n. If n is even, the algorithm divides it by two, and if n is odd, the algorithm multiplies it by three and adds one. The algorithm repeats this until n is one. Your task is to simulate the execution of the algorithm for a given value of n.',
    'The input consists of a single line containing an integer n.',
    'Print a line that contains all values of n during the algorithm.',
    '1 <= n <= 10^6',
    'Subtask 1: 1 <= n <= 100',
    'AUTHOR005');
