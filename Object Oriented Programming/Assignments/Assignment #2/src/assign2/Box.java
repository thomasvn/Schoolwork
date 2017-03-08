package assign2;

public class Box extends Block {
	private String type;

	public Box(double height, double depth, double length, String type) {
		super(height, depth, length);
		this.type = type;
	}
	
	public String getType() {
		return type;
	}

	public void setType(String type) {
		this.type = type;
	}

	@Override
	public String toString() {
		return "Box [type=" + type + " ,height=" + getHeight() + " ,length=" + getLength() + " ,depth=" + getDepth() + " ,volume=" + getVolume() + "]";
	}
}
