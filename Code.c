#include <linux/kernel.h>
#include <linux/list.h>
#include <linux/module.h>
#include <linux/sched.h>


asmlinkage lng sys_get_weight(int weight) {
if(weight <0) {
return -EINVAL:
}
curent->weight = weight;
return 0;
}



int traverse_children_sum_weight(struct task_struct* root_task) {
struct task_struct *task;
struct list_head *list;
int sum = root_task->weight;


list_for_each, &root_tak->children) {
task = list_entry(list, struct task_strcut, sibling);
sum += traverse_children_sum_weight(task, true);
}
return sum;


/* syscall implementation 
*/

asmlinkage long sys_get_total_weight(void) {
return traverse_children_sum_weight(current);
}
