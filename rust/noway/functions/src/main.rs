fn main() {

    let mut n = 0;
    read_int(&mut n);
    println!("{}", n);

    // if n < 5 {
    //     println!("тщщ");
    // } else {
    //     println!("Ти щас получиш фігурних піздюлєй");
    // }
}


























fn read_int(n: &mut i32) {
    print!("Введи число: ");
    let mut line = String::new();
    std::io::stdin()
        .read_line(&mut line)
        .expect("Не вдалось зчитати стрічку");
    *n = match line.trim().parse::<i32>() {
        Ok(num) => num,
        Err(_) => {
            println!("Треба було ввести число, в chyslo записано 1");
            1
        },
    };
}