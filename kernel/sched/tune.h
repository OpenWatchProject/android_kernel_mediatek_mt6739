
#ifdef CONFIG_SCHED_TUNE

#include <linux/reciprocal_div.h>

/*
 * System energy normalization constants
 */
struct target_nrg {
	unsigned long min_power;
	unsigned long max_power;
	struct reciprocal_value rdiv;
	unsigned long max_dyn_pwr[32];
	unsigned long max_stc_pwr[32];
};

struct target_cap {
	int cap;
	int freq;
};

extern struct target_nrg schedtune_target_nrg;

extern int stune_task_threshold;

void show_ste_info(void);
void show_pwr_info(void);

extern int sys_boosted;

#ifdef CONFIG_CGROUP_SCHEDTUNE

int schedtune_cpu_boost(int cpu);
int schedtune_task_boost(struct task_struct *tsk);

int schedtune_prefer_idle(struct task_struct *tsk);

void schedtune_enqueue_task(struct task_struct *p, int cpu);
void schedtune_dequeue_task(struct task_struct *p, int cpu);

#else /* CONFIG_CGROUP_SCHEDTUNE */

#define schedtune_cpu_boost(cpu)  get_sysctl_sched_cfs_boost()
#define schedtune_task_boost(tsk) get_sysctl_sched_cfs_boost()

#define schedtune_enqueue_task(task, cpu) do { } while (0)
#define schedtune_dequeue_task(task, cpu) do { } while (0)

#endif /* CONFIG_CGROUP_SCHEDTUNE */

int schedtune_normalize_energy(int energy);
int schedtune_accept_deltas(int nrg_delta, int cap_delta,
			    struct task_struct *task);

extern bool global_negative_flag;

#else /* CONFIG_SCHED_TUNE */

#define schedtune_cpu_boost(cpu)  0
#define schedtune_task_boost(tsk) 0

#define schedtune_enqueue_task(task, cpu) do { } while (0)
#define schedtune_dequeue_task(task, cpu) do { } while (0)

#define schedtune_accept_deltas(nrg_delta, cap_delta, task) nrg_delta

#endif /* CONFIG_SCHED_TUNE */
