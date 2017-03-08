package assign2;

public class Rectangle {
	private double length, width, area;

	public Rectangle(double length, double width) {
		this.length = length;
		this.width = width;
		this.area = length * width;
	}

	public double getLength() {
		return length;
	}

	public void setLength(double length) {
		this.length = length;
		this.area = this.length * this.width;
	}

	public double getWidth() {
		return width;
	}

	public void setWidth(double width) {
		this.width = width;
		this.area = this.length * this.width;
	}

	public double getArea() {
		return area;
	}
	
	@Override
	public String toString() {
		return "Rectangle [length=" + length + ", width=" + width + ", area=" + area + "]";
	}
}
