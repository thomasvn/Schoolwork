package assign2;

public class BedFrame extends Frame {
	private String size;
	private double height;

	public BedFrame(double length, double width, String material, String size, double height) {
		super(length, width, material);
		this.size = size;
		this.height = height;
	}

	public String getSize() {
		return size;
	}

	public void setSize(String size) {
		this.size = size;
	}

	public double getHeight() {
		return height;
	}

	public void setHeight(double height) {
		this.height = height;
	}

	@Override
	public String toString() {
		return "BedFrame [size=" + size + ", height=" + height + ", length=" + getLength() + ", width=" + getWidth()
				+ ", area=" + getArea() + ", material=" + getMaterial() + "]";
	}
}
