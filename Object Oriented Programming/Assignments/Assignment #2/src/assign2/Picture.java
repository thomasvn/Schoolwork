package assign2;

public class Picture {
	private double length, width;
	private String title, artist;

	public Picture(double length, double width, String title, String artist) {
		this.length = length;
		this.width = width;
		this.title = title;
		this.artist = artist;
	}

	public double getLength() {
		return length;
	}

	public void setLength(double length) {
		this.length = length;
	}

	public double getWidth() {
		return width;
	}

	public void setWidth(double width) {
		this.width = width;
	}

	public String getTitle() {
		return title;
	}

	public void setTitle(String title) {
		this.title = title;
	}

	public String getArtist() {
		return artist;
	}

	public void setArtist(String artist) {
		this.artist = artist;
	}

	@Override
	public String toString() {
		return "Picture [length=" + length + ", width=" + width + ", title=" + title + ", artist=" + artist + "]";
	}
}
