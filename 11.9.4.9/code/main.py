import matplotlib.pyplot as plt

# Read data from the .dat file
data_file = 'sums.dat'
with open(data_file, 'r') as file:
    lines = file.readlines()

# Parse the data into lists for plotting
n_values = []
sum_values = []
for line in lines[1:]:  # Skip the header
    n, summ = line.strip().split('\t')
    n_values.append(int(n))
    sum_values.append(int(summ))

# Plotting
plt.figure(figsize=(10, 6))
plt.plot(n_values, sum_values, marker='o', color='b', linestyle='-')
plt.title('Sum of the Series vs. n')
plt.xlabel('n')
plt.ylabel('Sum')
plt.grid(True)
plt.tight_layout()

# Save the plot to an existing directory
save_path = 'main.png'  # Update this path
plt.savefig(save_path)
