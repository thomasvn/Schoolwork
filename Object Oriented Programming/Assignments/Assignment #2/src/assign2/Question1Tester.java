package assign2;

public class Question1Tester {
	public static void main(String[] args) {
		// -------------------- Base Classes --------------------

		// -------------------- Ball --------------------
		System.out.println("------------------------------");
		Ball ball = new Ball(1);

		System.out.println("Ball Radius: " + ball.getRadius());
		System.out.println("Ball Volume: " + ball.getVolume());

		ball.setRadius(2);
		System.out.println(ball);

		// -------------------- Block --------------------
		System.out.println("------------------------------");
		Block block = new Block(1, 1, 1);

		System.out.println("Block Depth: " + block.getDepth());
		System.out.println("Block Height: " + block.getHeight());
		System.out.println("Block Length: " + block.getLength());
		System.out.println("Block Volume: " + block.getVolume());

		block.setDepth(2);
		block.setHeight(2);
		block.setLength(2);

		System.out.println(block);

		// -------------------- Frame --------------------
		System.out.println("------------------------------");
		Frame frame = new Frame(1, 1, "Balsa Wood");

		System.out.println("Frame Length: " + frame.getLength());
		System.out.println("Frame Width: " + frame.getWidth());
		System.out.println("Frame Material: " + frame.getMaterial());
		System.out.println("Frame Area: " + frame.getArea());

		frame.setLength(2);
		frame.setWidth(2);
		frame.setMaterial("Red Oak Wood");

		System.out.println(frame);

		// -------------------- Picture --------------------
		System.out.println("------------------------------");
		Picture picture = new Picture(1, 1, "Masterpiece", "BestArtist");

		System.out.println("Picture Length: " + picture.getLength());
		System.out.println("Picture Width: " + picture.getWidth());
		System.out.println("Picture Title: " + picture.getTitle());
		System.out.println("Picture Artist: " + picture.getArtist());

		picture.setLength(2);
		picture.setWidth(2);
		picture.setTitle("Mediocre Piece");
		picture.setArtist("Thomas");

		System.out.println(picture);

		// -------------------- Rectangle --------------------
		System.out.println("------------------------------");
		Rectangle rectangle = new Rectangle(1, 1);

		System.out.println("Rectangle Length: " + rectangle.getLength());
		System.out.println("Rectangle Width: " + rectangle.getWidth());
		System.out.println("Rectangle Area: " + rectangle.getArea());

		rectangle.setLength(2);
		rectangle.setWidth(2);

		System.out.println(rectangle);

		// --------------- Inherited / Composed Classes ---------------

		// -------------------- AlbumCover --------------------
		System.out.println("------------------------------");
		AlbumCover albumCover = new AlbumCover(1, "Great Music", "Thomas", "Eccentric", "January 1st, 2017");

		System.out.println("AlbumCover Picture Length: " + albumCover.getLength());
		System.out.println("AlbumCover Title: " + albumCover.getTitle());
		System.out.println("AlbumCover Artist: " + albumCover.getArtist());
		System.out.println("AlbumCover Genre: " + albumCover.getGenre());
		System.out.println("AlbumCover Release Date: " + albumCover.getReleaseDate());

		albumCover.setLength(2);
		albumCover.setTitle("Great Music: The Sequel");
		albumCover.setArtist("Thomas");
		albumCover.setGenre("More Eccentric");
		albumCover.setReleaseDate("January 2nd, 2017");

		System.out.println(albumCover);

		// -------------------- Basketball --------------------
		System.out.println("------------------------------");
		Basketball basketball = new Basketball(5, "Orange", 3);

		System.out.println("Basketball Radius: " + basketball.getRadius());
		System.out.println("Basketball Weight (Pounds): " + basketball.getLbs());
		System.out.println("Basketball Color: " + basketball.getColor());
		System.out.println("Basketball Volume: " + basketball.getVolume());

		basketball.setColor("Red");
		basketball.setLbs(5);
		basketball.setRadius(7);

		System.out.println(basketball);

		// -------------------- BedFrame --------------------
		System.out.println("------------------------------");
		BedFrame bedframe = new BedFrame(1000, 500, "Steel", "Queen", 300);

		System.out.println("BedFrame Length: " + bedframe.getLength());
		System.out.println("BedFrame Width: " + bedframe.getWidth());
		System.out.println("BedFrame Material: " + bedframe.getMaterial());
		System.out.println("BedFrame Size: " + bedframe.getSize());
		System.out.println("BedFrame Height: " + bedframe.getHeight());

		bedframe.setLength(2000);
		bedframe.setWidth(1000);
		bedframe.setMaterial("Wood");
		bedframe.setSize("King");
		bedframe.setHeight(500);

		System.out.println(bedframe);

		// -------------------- Box --------------------
		System.out.println("------------------------------");
		Box box = new Box(1, 1, 1, "Cardboard");

		System.out.println("Box Height: " + box.getHeight());
		System.out.println("Box Depth: " + box.getDepth());
		System.out.println("Box Length: " + box.getLength());
		System.out.println("Box Type: " + box.getType());
		System.out.println("Box Volume: " + box.getVolume());

		box.setDepth(2);
		box.setHeight(2);
		box.setLength(2);
		box.setType("Wooden");

		System.out.println(box);

		// -------------------- PictureFrame --------------------
		System.out.println("------------------------------");
		PictureFrame pictureFrame = new PictureFrame(5, 5, "Wood");
		Picture pic = new Picture(5, 5, "Mona Lisa", "Thomas");
		Picture result;

		System.out.println(pictureFrame);
		System.out.println(pic);

		pictureFrame.setPicture(pic);
		result = pictureFrame.getPicture();

		System.out.println("Picture Frame Length: " + pictureFrame.getLength());
		System.out.println("Picture Frame Width: " + pictureFrame.getWidth());
		System.out.println("Picture Frame Material: " + pictureFrame.getMaterial());
		System.out.println("Picture Length: " + result.getLength());
		System.out.println("Picture Width: " + result.getWidth());
		System.out.println("Picture Title: " + result.getTitle());
		System.out.println("Picture Artist: " + result.getArtist());

		pictureFrame.removePicture();
		System.out.println(pictureFrame);

		// -------------------- Glasses --------------------
		System.out.println("------------------------------");
		Glasses glasses = new Glasses(20, 20, 1, 2, "Plastic");

		System.out.println("Glasses Prescription (Left): " + glasses.getPrescription_left());
		System.out.println("Glasses Prescription (Right): " + glasses.getPrescription_right());
		System.out.println("Glasses Frame Length: " + glasses.getFrameLength());
		System.out.println("Glasses Frame Width: " + glasses.getFrameWidth());
		System.out.println("Glasses Material: " + glasses.getFrameMaterial());

		glasses.setPrescription_left(19);
		glasses.setPrescription_right(19);
		glasses.changeFrame(2, 3, "Metal");

		System.out.println(glasses);

		// -------------------- Square --------------------
		System.out.println("------------------------------");
		Square square = new Square(1);
		
		System.out.println("Square Side Length: " + square.getSide_length());
		System.out.println("Square Area: " + square.getArea());
		
		square.setSide_length(5);
		
		System.out.println(square);
	}
}
