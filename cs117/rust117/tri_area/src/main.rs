use std::io;

fn main() {
    let base: f32 = get_base();
    let height: f32 = get_height();
    let area: f32 = get_area(&base, &height); 
    display_data(&base, &height, &area);
}

fn get_base()-> f32 {
    let mut user_input = String::new();
    io::stdin().read_line(&mut user_input).expect("err");
    let user_num : f32 = user_input.trim().parse().unwrap();
    return user_num;
}

fn get_height()-> f32 {
    let mut user_input = String::new();
    io::stdin().read_line(&mut user_input).expect("err");
    let user_num : f32 = user_input.trim().parse().unwrap();
    return user_num;
}

fn get_area(base: &f32, height: &f32)-> f32 {
    return base * height * 0.5;
}

fn display_data(base: &f32, height: &f32, area: &f32) {
    println!("{area}");
}