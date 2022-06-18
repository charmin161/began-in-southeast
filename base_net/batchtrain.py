import torch
import torch.utils.data as Data

batch_size = 5


x = torch.linspace(1,10,10)
y = torch.linspace(10,1,10)

#data_tensor=x, target_tensor=y
torch_dataset = Data.TensorDataset(x, y)

loader = Data.DataLoader(
    dataset = torch_dataset,
    batch_size = batch_size,
    shuffle = True,
    #num_workers = 2
)

for epoch in range(3):
    #每个loader 对应step的索引
    for step, (batch_x, batch_y) in enumerate(loader):
        #training
        print('epoch:', epoch, '| step',step,' | batch x:', batch_x.numpy(), '| batch y:',batch_y.numpy())

