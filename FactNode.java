public class FactNode {
	private String fact;
	private String category;
	public FactNode next;
	public FactNode(String fact, String category)
	{
		fact = this.fact;
		category = this.category;
		next = null;
	}
	public FactNode(String fact, String category, FactNode next)
	{
		fact = this.fact;
		category = this.category;
		next = this.next;
	}
	public String toString()
	{
		return fact;
	}
	public String getCategory()
	{
		return category;
	}
}
