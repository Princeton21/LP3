// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;
contract BankAccount {
    address public owner;
    uint256 public balance;
    constructor() {
        owner = msg.sender;
        balance = 0;
    }
    modifier onlyOwner() {
        require(msg.sender == owner);
        _;
    }
    function deposit(uint256 amount) public onlyOwner {
        require(amount > 0);
        balance += amount;
    }

    function withdraw(uint256 amount) public onlyOwner {
        require(amount > 0);
        require(amount <= balance);
        balance -= amount;
    }
    
    function getBalance() public view returns (uint256) {
        return balance;
    }
}