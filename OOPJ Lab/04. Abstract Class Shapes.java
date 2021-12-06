/*Write a java program to create an abstract class named Shape that contains an
empty method named numberOfSides( ). Provide three classes named
Rectangle, Triangle and Hexagon such that each one of the classes extends the
class Shape. Each one of the classes contains only the method numberOfSides( )
that shows the number of sides in the given geometrical structures.*/


abstract class Shape{
   abstract void numberOfSides();
}
class Recttangle extends Shape{
    void numberOfSides(){
        System.out.println("Number of sides of a Rectangle is 4");
    }
}
class Triiangle extends Shape{
    void numberOfSides(){
        System.out.println("Number of sides of a Triangle is 3");
    }
}
class Hexagon extends Shape{
    void numberOfSides(){
        System.out.println("Number of sides of a Hexagon is 6");
    }
}
public class AbstractClassShapesEg {
    public static void main(String[] args) {
        Recttangle rect = new Recttangle();
        rect.numberOfSides();
        Triiangle tri = new Triiangle();
        tri.numberOfSides();
        Hexagon hex = new Hexagon();
        hex.numberOfSides();
    }
}
