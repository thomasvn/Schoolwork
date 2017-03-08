package assign2;

public class Frame {
	private double length, width, area;
	private String material;

	public Frame(double length, double width, String material) {
		this.length = length;
		this.width = width;
		this.material = material;
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

	public String getMaterial() {
		return material;
	}

	public void setMaterial(String material) {
		this.material = material;
	}

	@Override
	public String toString() {
		return "Frame [length=" + length + ", width=" + width + ", area=" + area + ", material=" + material + "]";
	}
}
