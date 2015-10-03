//This is to count the number of facts in each category
public class CategoryCount {
	private String category;
	private int count;
	public CategoryCount(String cat, int count)
	{
		category = cat;
		this.count = count;
	}
	public void increment()
	{
		count++;
	}
	public int getCount()
	{
		return count;
	}
	public String getCategory()
	{
		return category;
	}
	

}
