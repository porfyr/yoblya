use std::io::Write;
use rand::Rng;

fn main() {
    let mut matrix = [          // Ініціалізація пустої таблички
        ['.', '.', '.'],       // хрестики нолики
        ['.', '.', '.'],
        ['.', '.', '.']
    ];
    
    loop {
        if check_won(matrix) {
            break;
        }
        print_situation(matrix);
        ask_for_step(&mut matrix);
        if check_won(matrix) {
            break;
        }
        print_situation(matrix);
        bot_step_rand(&mut matrix);
    }
}

fn print_situation(matrix: [[char; 3]; 3]) {
    for i in matrix.iter() {
        for sy in i {
            print!("{} ", sy);
        }
        println!();
    }
}

fn check_won(matrix: [[char; 3]; 3]) -> bool {
    let combs = [
		[ [0,0], [0,1], [0,2] ],
		[ [1,0], [1,1], [1,2] ],
		[ [2,0], [2,1], [2,2] ],
        [ [0,0], [1,0], [2,0] ],
        [ [0,1], [1,1], [2,1] ],
        [ [0,2], [1,2], [2,2] ],
        [ [0,0], [1,1], [2,2] ],
        [ [2,0], [1,1], [0,2] ],
    ];
    for comb in combs {
        if matrix[comb[0][0]][comb[0][1]] == matrix[comb[1][0]][comb[1][1]] &&
           matrix[comb[1][0]][comb[1][1]] == matrix[comb[2][0]][comb[2][1]] &&
           matrix[comb[0][0]][comb[0][1]] != '.'
        {
            println!("Хтось виграв");
            print_situation(matrix);
            return true;
        }
    }
    return false;
}

fn ask_for_step(matrix: &mut [[char; 3]; 3]) {
    println!("Твій хід");
    let mut row: usize = 0;
    let mut col: usize = 0;
    loop {
        read_int("рядок: ", &mut row);
        read_int("стовпець: ", &mut col);
        row -= 1;
        col -= 1;
        if row > 3 || col > 3 || matrix[row][col] != '.'{
            println!("Ти втикнув у зайняту клітинку або вийшов за межі");
            continue;
        } else {
            matrix[row][col] = 'x';
            break;
        }
    }
}

fn read_int(text: &str, n: &mut usize) {
    print!("{}", text);
    _ = std::io::stdout().flush();
    let mut line = String::new();
    std::io::stdin()
        .read_line(&mut line)
        .expect("Не вдалось зчитати стрічку");
    *n = match line.trim().parse::<usize>() {
        Ok(num) => num,
        Err(_) => {
            println!("Треба було ввести число, в chyslo записано 1");
            1
        },
    };
}

fn bot_step_rand(matrix: &mut [[char; 3]; 3]) {
    println!("Бот ходить:");
    loop {
        let col = rand::thread_rng().gen_range(0, 3);
        let row = rand::thread_rng().gen_range(0, 3);
        if matrix[row][col] != '.' {
            continue;
        } else {
            matrix[row][col] = 'o';
            break;
        }
    }
}