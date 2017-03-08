package assign2;

public class Glasses {
	private double prescription_left, prescription_right;
	private Frame frame;
	
	public Glasses(double prescription_left, double prescription_right, double frame_length, double frame_width, String material) {
		this.prescription_left = prescription_left;
		this.prescription_right = prescription_right;
		frame = new Frame(frame_length, frame_width, material);
	}

	public double getPrescription_left() {
		return prescription_left;
	}

	public void setPrescription_left(double prescription_left) {
		this.prescription_left = prescription_left;
	}

	public double getPrescription_right() {
		return prescription_right;
	}

	public void setPrescription_right(double prescription_right) {
		this.prescription_right = prescription_right;
	}
	
	public double getFrameLength() {
		return frame.getLength();
	}
	
	public double getFrameWidth() {
		return frame.getWidth();
	}
	
	public String getFrameMaterial() {
		return frame.getMaterial();
	}
	
	public void changeFrame(double length, double width, String material) {
		frame = new Frame(length, width, material);
	}

	@Override
	public String toString() {
		return "Glasses [prescription_left=" + prescription_left + ", prescription_right=" + prescription_right
				+ ", frame_length=" + getFrameLength() + ", frame_width=" + getFrameWidth()
				+ ", frame_material=" + getFrameMaterial() + "]";
	}
}
