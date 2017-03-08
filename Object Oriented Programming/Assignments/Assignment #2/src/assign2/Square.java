package assign2;

public class Square extends Rectangle {
	private double side_length;
	
	public Square(double side_length) {
		super(side_length, side_length);
		this.side_length = side_length;
	}

	public double getSide_length() {
		return side_length;
	}

	public void setSide_length(double side_length) {
		this.side_length = side_length;
		super.setLength(side_length);
		super.setWidth(side_length);
	}

	@Override
	public String toString() {
		return "Square [side_length=" + side_length + ", area=" + super.getArea() + "]";
	}
}
