package assign2;

public class AlbumCover extends Picture {
	private String genre, releaseDate;

	public AlbumCover(double length, String title, String artist, String genre, String releaseDate) {
		super(length, length, title, artist);
		this.genre = genre;
		this.releaseDate = releaseDate;
	}

	public String getGenre() {
		return genre;
	}

	public void setGenre(String genre) {
		this.genre = genre;
	}

	public String getReleaseDate() {
		return releaseDate;
	}

	public void setReleaseDate(String releaseDate) {
		this.releaseDate = releaseDate;
	}
	
	@Override
	public void setLength(double length) {
		super.setLength(length);
		super.setWidth(length);
	}

	@Override
	public String toString() {
		return "AlbumCover [genre=" + genre + ", releaseDate=" + releaseDate + ", length=" + super.getLength()
				+ ", width=" + super.getWidth() + ", title=" + super.getTitle() + ", artist=" + super.getArtist()
				+ ", getGenre()=" + getGenre() + ", getReleaseDate()=" + getReleaseDate() + "]";
	}
}
