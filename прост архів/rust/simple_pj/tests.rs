fn main()
{
    let mut x:i32 = 8;
    change (&mut x);
    println!("В main x = {}", x);
}

fn change (n: &mut i32)
{
    *n += 1;
    println!("В функції x = {}", n);
}