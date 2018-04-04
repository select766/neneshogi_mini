const path = require('path');

module.exports = {
    mode: 'development',
    entry: './src/index.ts',
    module: {
        rules: [
            {
                test: /\.ts$/,
                use: 'ts-loader'
            }
        ]
    },
    resolve: {
        extensions: [
            '.ts', '.js'
        ]
    },
    output: {
        filename: 'bundle.js',
        path: path.join(__dirname, 'docs/js')
    }
};
