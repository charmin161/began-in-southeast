import matplotlib.pyplot as plt
import torch
import torch.nn as nn
import torch.utils.data as Data
import torchvision
from torch.autograd import Variable

#Hyper Parameters

EPOCH = 1 #train the training data n times 
BATCH_SIZE = 50
LR = 0.001
DOWNLOAD_MNIST = False

train_data = torchvision.datasets.MNIST(
    root = './mnist',
    train  = True,
    transform = torchvision.transforms.ToTensor(), #(0,1)
    download = DOWNLOAD_MNIST

)

#plot one example

# print(train_data.train_data.size())

# print(train_data.train_labels.size())

# plt.imshow(train_data.train_data[0].numpy(), cmap = 'gray')
# plt.title('%i'%train_data.train_labels[0])
# plt.show()


train_loader = Data.DataLoader(
    dataset = torch_dataset,
    batch_size = BATCH_SIZE,
    shuffle = True,
    #num_workers = 2
)

test_data = torchvision.datasets.MNIST(
    root = './mnist',
    train = False
)

test_x = Variable(torch.unsqueeze(test_data.test_data,dim = 1),volatile = True).type(torch.FloatTensor)[:2000]/255.
test_y = test_data.test_labels[:2000]

class CNN(nn.Moudle):
    def __init__(self):
        super(CNN,self).__init__()
        self.conv1 = nn.Sequential(
            nn.Conv2d(
                in_channels = 1,
                out_channels = 16,
                kernel_size = 5,
                stride = 1,
                padding = 2 #if stride = 1,pad  = (kernal_size - 1)/2
            ), #->16,28,28
            nn.RELU(), # 16,28,28
            nn.MaxPool2d(kernal_size = 2) #16,14,14
        )
        self.conv2 = nn.Sequential(
            nn.Conv2d(16,32,5,1,2), #32,14,14
            nn.RELU(), 
            nn.MaxPool2d(2) #32,7,7
        )
        self.out = nn.Linear(32*7*7,10)

    def forward(self, x):
        x = self.conv1(x)
        x = self.conv2(x)          #(batch ,32, 7 ,7)
        x = x.view(x.size(0), -1)  #展平(batch,32*7*7)
        output = self.out(x)
        return output 

    cnn  = CNN()

    #cnn.cuda()

    optimizer = torch.optim.Adam(cnn.parameters(), lr = LR)

    loss_func = nn.CrossEntropyLoss()

    for epoch in range(EPOCH):
        for step,(x, y) in enumerate(train_loader):
            b_x = Variable(x)
            b_y = Variable(y)
##使用GPU的话
##          b_x = Variable(x).cuda()
 
##          b_y = Variable(y).cuda()


            output = cnn(b_x)
            loss = loss_func(output,b_y)
            

            optimizer.zero_grad()
            loss.backward()
            optimizer.step()

            if step %50 == 0:
                test_output = cnn(test_x)
                pred_y = torch.max(test_output,1)[1].data.squeeze()

            #pred_y = torch.max(test_output,1)[1].cuda().data.squeeze()
                
                accuracy = sum(pred_y == test_y)/test_y.size(0)
                print('data')

test_output = cnn(test_x)[:10]
pred_y = torch.max(test_output,1)[1].data.numpy().squeeze()

##使用GPU的话
##pred_y = torch.max(test_output,1)[1].cuda().data.numpy().squeeze() 
