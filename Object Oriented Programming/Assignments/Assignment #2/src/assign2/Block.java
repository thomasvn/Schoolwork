package assign2;

public class Block {
	private double height, depth, length, volume;

	public Block(double height, double depth, double length) {
		this.height = height;
		this.depth = depth;
		this.length = length;
		this.volume = this.length * this.depth * this.height;
	}

	public double getHeight() {
		return height;
	}

	public void setHeight(double height) {
		this.height = height;
		this.volume = this.length * this.depth * this.height;
	}

	public double getDepth() {
		return depth;
	}

	public void setDepth(double depth) {
		this.depth = depth;
		this.volume = this.length * this.depth * this.height;
	}

	public double getLength() {
		return length;
	}

	public void setLength(double length) {
		this.length = length;
		this.volume = this.length * this.depth * this.height;
	}
	
	public double getVolume() {
		return this.volume;
	}

	@Override
	public String toString() {
		return "Block [height=" + height + ", depth=" + depth + ", length=" + length + "]";
	}
}
