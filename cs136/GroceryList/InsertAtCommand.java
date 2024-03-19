import java.util.ArrayList;

public class InsertAtCommand extends UndoCommand {
	// Your field declarations here
	private ArrayList<String>sourceList;
	private int index;
	private String val;
	// Your constructor code here
	public InsertAtCommand(int i, String s, ArrayList<String>lst) {
		this.sourceList = lst;
		this.index = i;
		this.val = s;
	}
	
	@Override
	public void execute() {
		// Your code here
		sourceList.add(index, val);
	}
}
