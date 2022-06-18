import matplotlib.pyplot as plt
import torch
import torch.nn.functional as F
from torch.autograd import Variable

x = torch.unsqueeze(torch.linspace(-1, 1, 100), dim = 1)
y = x.pow(2) + 0.2*torch.rand(x.size())

x,y = Variable(x), Variable(y)

# plt.scatter(x.data.numpy(), y.data.numpy())
# plt.show()


#method1
class Net(torch.nn.Module):
    def __init__(self, n_features, n_hidden, n_output):
        super(Net, self).__init__()
        self.hidden = torch.nn.Linear(n_features, n_hidden)
        self.predict = torch.nn.Linear(n_hidden, n_output)



    def forward(self, x):
        x = F.relu(self.hidden(x))
        x = self.predict(x)
        return x

net1 = Net(1, 10, 1)


#method2
net2 = torch.nn.Sequential{
    torch.nn.Linear(1,10),
    torch.nn.RELU(),
    torch.nn.Linear(10,1)
    
}

#可视化

plt.ion  
plt.show()

#优化神经网络
optimizer = torch.optim.SGD(net1.parameters(), lr = 0.5)

loss_func = torch.nn.MSELoss()

for t in range(100):
    prediction = net1(x)
    loss = loss_func(prediction, y)

#优化步骤
    #先梯度降维0
    optimizer.zero_grad()
    loss.backward()
    optimizer.step()
    
    if t % 5 == 0:
        plt.cla()
        plt.scatter(x.data.numpy(), y.data.numpy())
        plt.plot(x.data.numpy(), prediction.data.numpy(),'r-', lw = 5, )
        plt.text(0.5, 0, 'Loss=%.4f' % loss.data, fontdict={'size':20, 'color': 'red'})
        plt.pause(0.1)

plt.ioff()
plt.show()


