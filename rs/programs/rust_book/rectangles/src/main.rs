#[derive(Debug)]
struct Rectangle {
    width: u32,
    height: u32,
}

impl Rectangle {
    fn area(&self) -> u32 {
        self.width * self.height
    }

    fn can_hold(&self, other: &Rectangle) -> bool {
        self.width > other.width && self.height > other.height
    }

    fn build_square(side_length: u32) -> Rectangle {
        Rectangle {width: side_length, height: side_length}
    }
}

fn main() {
    let rect1 = Rectangle {width: 30, height: 50};
    let rect2 = Rectangle {width: 25, height: 45};
    let square = Rectangle::build_square(50);

    println!("rect1 is {:?}", rect1);
    println!("square is {:?}", square);
    println!("The area of the rectangle is {} square pixels", rect1.area());

    println!("Can rect1 hold rect2? {}", rect1.can_hold(&rect2));

}