mod notmain;

fn main() {
    let mut x : i8 = 5;
    notmain::get_num(&mut x);
    println!("{}",x);
}