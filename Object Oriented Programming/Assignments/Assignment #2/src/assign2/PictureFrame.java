package assign2;

public class PictureFrame extends Frame {
	private Picture picture;
	private Boolean hasPicture;

	public PictureFrame(double length, double width, String material) {
		super(length, width, material);
		this.hasPicture = false;
	}
	
	public Picture getPicture() {
		if (this.hasPicture) {
			return picture;
		}
		else {
			System.out.println("No picture is in the Frame");
			return null;
		}
	}
	
	public void setPicture(Picture newPicture) {
		if (newPicture.getLength() > this.getLength() || newPicture.getWidth() > this.getWidth()) {
			System.out.println("Picture you are trying to insert is too big");
			return;
		}
		
		this.picture = newPicture;
		this.hasPicture = true;
	}
	
	public void removePicture() {
		if (this.hasPicture) {
			this.hasPicture = false;
			System.out.println("Picture has been removed");
		} else {
			System.out.println("Cannot Remove. There is currently no picture in the frame.");
		}
	}

	@Override
	public String toString() {
		return "PictureFrame [hasPicture=" + hasPicture + ", length=" + getLength() + ", width=" + getWidth()
				+ ", area=" + getArea() + ", material=" + getMaterial() + "]";
	}


}
