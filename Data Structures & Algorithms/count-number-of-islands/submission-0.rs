impl Solution {
    pub fn num_islands(mut grid: Vec<Vec<char>>) -> i32 {
        let rows = grid.len();
        if rows == 0 {
            return 0;
        }
        let cols = grid[0].len();
        let mut islands = 0;

        for r in 0..rows {
            for c in 0..cols {
                if grid[r][c] != '1' {
                    continue;
                }

                islands += 1;
                grid[r][c] = '0';
                let mut stack = vec![(r, c)];

                while let Some((row, col)) = stack.pop() {
                    let neighbours = [
                        (row.wrapping_sub(1), col),
                        (row + 1, col),
                        (row, col.wrapping_sub(1)),
                        (row, col + 1),
                    ];

                    for (nr, nc) in neighbours {
                        if nr < rows && nc < cols && grid[nr][nc] == '1' {
                            grid[nr][nc] = '0';
                            stack.push((nr, nc));
                        }
                    }
                }
            }
        }

        islands

    }
}
