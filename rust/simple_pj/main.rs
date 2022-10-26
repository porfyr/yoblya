fn main()
{
    let mut x: i32 = 0;
    let mut y: i32 = 1;
    //input (&mut x);
    //input (&mut y);

    let mut _temp = 0;

    loop {
        println!("{x} {y}");
        _temp = y;
        y += x;
        x = _temp;
        if x > 1000 {
            break;
        }
    }
    

    println!("{} {}", x, y);
}

fn input (n: &mut i32)  // Викликається input(&mut value);
{
    println!("Введи чисво");
    let mut inp = String::new();
    std::io::stdin().read_line(&mut inp);
    *n = inp.trim().parse().unwrap();
}
















/*

    // інпут числа
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).expect("Хотів ввести щось.");
    let x:i32 = input.trim().parse().unwrap();
    println!("{}", x + 1)


*/