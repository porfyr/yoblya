use std::io;
use std::cmp::Ordering;
use rand::Rng;

fn main() {
    println!("Ану давай число: ");

    let secret_n = rand::thread_rng().gen_range(1, 101);
    println!("Секретне число: {}", secret_n);    
    
    loop {
            let mut n = String::new();
            io::stdin().read_line(&mut n)
                .expect("Не вдалось прочитати рядок");

            let n: u32 = match n.trim().parse() {
                Ok(num) => num,
                Err(_) => continue,
            };

            match n.cmp(&secret_n) {
            Ordering::Less => println!("Замале"),
            Ordering::Greater => println!("Завелике"),
            Ordering::Equal => {
                println!("Ти виграв");
                break;
            }
        }
    }
}
