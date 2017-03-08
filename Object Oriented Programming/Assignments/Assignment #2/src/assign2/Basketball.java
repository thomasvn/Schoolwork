package assign2;

public class Basketball extends Ball {
	private String color;
	private double lbs;

	public Basketball(double radius, String color, double lbs) {
		super(radius);
		this.color = color;
		this.lbs = lbs;
	}

	public String getColor() {
		return color;
	}

	public void setColor(String color) {
		this.color = color;
	}

	public double getLbs() {
		return lbs;
	}

	public void setLbs(double lbs) {
		this.lbs = lbs;
	}

	@Override
	public String toString() {
		return "Basketball [color=" + color + ", lbs=" + lbs + ", Radius=" + getRadius() + ", Volume=" + getVolume()
				+ "]";
	}
}
