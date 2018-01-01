//--------------------------------------------------------------------
//
//  Laboratory 10                                             ptyQueue.h
//
//  Class declaration for the array implementation of the Heap ADT
//
//--------------------------------------------------------------------

const int defMaxQueueSize = 10; // Default maximum queue size

template < class DT >
class PtyQueue : public Heap<DT>
{
public:
	// Constructor
	PtyQueue(int maxNumber = defMaxQueueSize);

	// Queue manipulation operations
	void enqueue(const DT &newDataItem) throw (logic_error); // Enqueue data data item

	DT dequeue() throw (logic_error); // Dequeue data data item
};