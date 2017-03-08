package assign2;

public class Ball {
	private double radius, volume;

	public Ball(double radius) {
		this.radius = radius;
		this.volume = (4 / 3) * Math.PI * Math.pow(radius, 3);
	}

	public double getRadius() {
		return radius;
	}

	public void setRadius(double radius) {
		this.radius = radius;
		this.volume = (4 / 3) * Math.PI * Math.pow(radius, 3);
	}

	public double getVolume() {
		return volume;
	}

	@Override
	public String toString() {
		return "Ball [radius=" + radius + ", volume=" + volume + "]";
	}
}
