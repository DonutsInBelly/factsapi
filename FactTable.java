import java.util.ArrayList;
public class FactTable {
	private FactNode[] Hashtable;
	private ArrayList<CategoryCount> counts; // The number of facts in each category will help randomize the output
	public FactTable()
	{
		Hashtable= new FactNode[100];
		counts = new ArrayList<CategoryCount>();
	}
	private static int hash(String category)//very predictable, we don't need sporadic behavior. Sparse enough.
	{
		int hasher=0;
		for(int i = 0; i<category.length();i++)
		{
			hasher+=(int) category.charAt(i);
		}
		hasher = hasher %100;
		return hasher;
	}
	public void put(FactNode fact)
	{
		int hasher = hash(fact.getCategory());
		fact.next = Hashtable[hasher];
		String cat = fact.getCategory();
		for(int i = 0; i< counts.size(); i++)//Increment the count of facts in the category.
		{
			if(counts.get(i).getCategory().equals(fact.getCategory()))
			{
				counts.get(i).increment();
				return;
			}
		}
		counts.add(new CategoryCount(cat,1));//In case not there, make new category
	}
	public FactNode get(String category)
	{
		int numFacts = 0;
		for(int i = 0; i<counts.size();i++)//retrieve the number of facts in the category
		{
			if(counts.get(i).getCategory().equals(category));
			{
				numFacts = counts.get(i).getCount();
				break;
			}
		}
		if(numFacts==0)
		{
			System.out.println("Error, category not found in arraylist CategoryCount");
			return null;
		}
		int rand = (int)(Math.random()*numFacts)+1;
		int hasher = hash(category);
		FactNode curr = Hashtable[hasher];
		while(true)//get the rand-th fact in that category
		{
			if(curr.getCategory()==category)
				rand--;
			if(rand ==0)
				return curr;
			curr = curr.next;
		}
	}
	
	

}
