import java.util.ArrayList;

public class SwapCommand extends UndoCommand {
	// Your field declarations here
	private ArrayList<String> sourceList; 
	private int i1;
	private int i2;
	
	// Your constructor code here
	public SwapCommand(int index1, int index2, ArrayList<String>lst) {
		this.sourceList = lst;
		this.i1 = index1;
		this.i2 = index2;
	}

	@Override
	public void execute() {
		// Your code here
		String temp = sourceList.get(i1);
		sourceList.set(i1, sourceList.get(i2));
		sourceList.set(i2, temp);
	}

}
